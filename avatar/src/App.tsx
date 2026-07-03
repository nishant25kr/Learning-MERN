import { useState, useEffect } from "react";
import { motion } from "framer-motion";

const STEP_SIZE = 25; 

export default function app() {
  const [position, setPosition] = useState({ x: 100, y: 100 });
  const [facingLeft, setFacingLeft] = useState(false);

  useEffect(() => {
    const handleKeyDown = (event: any) => {
      switch (event.key) {
        case "ArrowUp":
        case "w":
          setPosition((prev) => ({ ...prev, y: Math.max(0, prev.y - STEP_SIZE) }));
          break;
        case "ArrowDown":
        case "s":
          setPosition((prev) => ({ ...prev, y: prev.y + STEP_SIZE }));
          break;
        case "ArrowLeft":
        case "a":
          setPosition((prev) => ({ ...prev, x: Math.max(0, prev.x - STEP_SIZE) }));
          setFacingLeft(true);
          break;
        case "ArrowRight":
        case "d":
          setPosition((prev) => ({ ...prev, x: prev.x + STEP_SIZE }));
          setFacingLeft(false);
          break;
        default:
          break;
      }
    };

    // Attach event listener to the window object
    window.addEventListener("keydown", handleKeyDown);
    return () => window.removeEventListener("keydown", handleKeyDown);
  }, []);

  return (
    <div style={{ width: "100vw", height: "100vh", background: "#f0f0f0", position: "relative", overflow: "hidden" }}>
      <p style={{ position: "absolute", top: 10, left: 10, fontFamily: "sans-serif" }}>
        Use <b>Arrow Keys</b> or <b>WASD</b> to move the avatar.
      </p>

      <motion.div
        animate={{ 
          x: position.x, 
          y: position.y,
          scaleX: facingLeft ? -1 : 1 
        }}
        transition={{ type: "spring", stiffness: 200, damping: 20 }} 
        style={{
          position: "absolute",
          width: "80px",
          height: "80px",
          cursor: "pointer"
        }}
      >
        <img 
          src="https://www.google.com/imgres?q=avatar&imgurl=https%3A%2F%2Fsm.ign.com%2Fign_ap%2Fcover%2Fa%2Favatar-gen%2Favatar-generations_hugw.jpg&imgrefurl=https%3A%2F%2Fsea.ign.com%2Favatar-generations&docid=C1woOSHDtEy36M&tbnid=iK0aSJqa8CD5XM&vet=12ahUKEwixpNivmZ-VAxVUSmwGHcueGsAQnPAOegUI2wEQAA..i&w=1024&h=1024&hcb=2&ved=2ahUKEwixpNivmZ-VAxVUSmwGHcueGsAQnPAOegUI2wEQAA" 
          alt="2D Avatar" 
          style={{ width: "100%", height: "100%" }}
        />
      </motion.div>
    </div>
  );
}
