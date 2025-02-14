// import React, { Component } from "react"
// import { useState } from "react"
// import image1 from './images/image1.jpg'
// import image2 from './images/image2.jpg'
// export default function App() {
//   const picture = [image1]
//   const [state, setState] = useState(picture)
//   const handler = () => {
//     setState([...state, image2])
//   };
//   return (
//     <div>
//       {state.map((img, index) => (
//         <img src={img} width="200px" alt={`Image ${index}`} />
//       ))}
//       <button onClick={handler}>Click me</button>
//     </div>
//   )
// }



import React from "react";
import { Swiper, SwiperSlide } from "swiper/react";
import { Navigation } from "swiper/modules";  // ✅ Correct import
import "swiper/css";
import "swiper/css/navigation";

const projects = [
  { id: 1, image: "/projects/project1.png", title: "Library Management" },
  { id: 2, image: "/projects/project2.png", title: "E-Commerce App" },
];

const ProjectCarousel = () => {
  return (
    <div className="p-5">
      <Swiper navigation={true} modules={[Navigation]} className="w-full h-64">
        {projects.map((project) => (
          <SwiperSlide key={project.id}>
            <img src={project.image} alt={project.title} className="w-full h-full object-cover" />
          </SwiperSlide>
        ))}
      </Swiper>
    </div>
  );
};

export default ProjectCarousel;
