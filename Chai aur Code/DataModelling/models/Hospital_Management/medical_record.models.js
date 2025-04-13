import mongoose from "mongoose";

const medicalSchema = new mongoose.Schema({},{timestamps:true});

export const Medical_report = mongoose.model("Medical_report",medicalSchema);

