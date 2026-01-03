const rateLimit = require("express-rate-limit");
const helmet = require("helmet");

// 1. Rate Limiting: Prevent Brute Force
const loginLimiter = rateLimit({
  windowMs: 15 * 60 * 1000, // 15 minutes
  max: 10, // Limit each IP to 10 login attempts per window
  message: { message: "Too many login attempts, please try again after 15 minutes" }
});

// Route definition
router.post(
  "/login",
  helmet(),        // 2. Security Headers
  loginLimiter,    // 3. Rate Limit Middleware
  [
    body("username").isString().trim().escape().notEmpty(),
    body("password").isString().notEmpty(),
  ],
  async (req, res) => {
    try {
      // 4. Validation Check
      const errors = validationResult(req);
      if (!errors.isEmpty()) {
        return res.status(400).json({ success: false, errors: errors.array() });
      }

      const { username, password } = req.body;

      // 5. Secure Query (Prevent NoSQL Injection)
      const user = await User.findOne({ username: String(username) }).select("+password");
      
      // Generic error message to prevent account enumeration
      if (!user || !(await bcrypt.compare(password, user.password))) {
        return res.status(401).json({
          success: false,
          message: "Invalid username or password",
        });
      }

      // 6. Generate Token
      const token = jwt.sign(
        { userId: user._id },
        process.env.JWT_SECRET,
        { expiresIn: "15m" } // Short-lived access token
      );

      // 7. Secure Cookie Delivery (Prevents XSS)
      res.cookie("token", token, {
        httpOnly: true,     // Prevents JavaScript access
        secure: process.env.NODE_ENV === "production", // HTTPS only
        sameSite: "strict", // Prevents CSRF
        maxAge: 15 * 60 * 1000, 
      });

      res.status(200).json({
        success: true,
        user: { id: user._id, username: user.username },
      });
    } catch (error) {
      // 8. Centralized Logging (Avoid logging sensitive data)
      logger.error(`Login Error: ${error.message}`); 
      res.status(500).json({ success: false, message: "An internal error occurred" });
    }
  }
);