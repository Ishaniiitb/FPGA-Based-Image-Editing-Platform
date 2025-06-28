# FPGA-Based Image Editing Platform

This project simulates an image editing platform designed for implementation on an FPGA. Written in C++, it supports a range of basic image processing operations applied to BMP images. The platform can serve as a testbench or as the foundation for an image-processing IP core in hardware.

## 🧰 Features

- Brightness Adjustment
- Contrast Enhancement
- Image Flipping (horizontal/vertical)
- Grayscale Conversion
- Color Inversion
- Sepia Filter
- BMP File Input/Output

## 📁 File Structure

Project/
│

├── Brighten.cpp / .h # Brightens the image

├── Contrast.cpp / .h # Modifies image contrast

├── Flip.cpp / .h # Flips the image horizontally/vertically

├── Grayscale.cpp / .h # Converts RGB to grayscale

├── Invert.cpp / .h # Inverts RGB colors

├── Sepia.cpp / .h # Applies sepia tone

├── ReadBMP.cpp / .h # Reads BMP image files

├── WriteBMP.cpp / .h # Writes BMP image files

├── WriteImage.cpp / .h # Helper for image output

├── TestBench.cpp # Main testing file

├── Image[1-4].bmp # Sample input images

├── Result.bmp # Output image after processing


## 🚀 Getting Started

### Prerequisites

- C++ Compiler (e.g., `g++`)
- BMP image files (24-bit)

## 📷 Example
Input: Image1.bmp

Output: Result.bmp with selected filters applied (as defined in TestBench.cpp).

## 🛠️ Implementation Notes
While this is a software simulation, the modular design is suitable for hardware synthesis on FPGA platforms using HLS tools. Each image operation could be synthesized as a separate module.

### Compilation

Use the following command to compile:

```bash
g++ -o image_editor TestBench.cpp Brighten.cpp Contrast.cpp Flip.cpp Grayscale.cpp Invert.cpp Sepia.cpp ReadBMP.cpp WriteBMP.cpp WriteImage.cpp
