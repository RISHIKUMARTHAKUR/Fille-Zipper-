
## 📦 FILE ZIPPER 

### 🛠 Tools & Technologies Used

* Visual Studio Code
* C++
* Algorithms (Greedy)
* GitHub

### 🚀 Project Overview

**File Zipper** is a C++ implementation of a **Huffman Encoder**, a classic greedy algorithm used for **lossless data compression**. It compresses a given file by assigning variable-length binary codes to characters based on their frequencies—characters used more often get shorter codes. This significantly reduces the file size while ensuring no data loss during decompression.

### 💡 Key Features

* Implements **Huffman Encoding** for file compression
* Efficient **priority queue (min-heap)** usage for building the Huffman Tree
* Supports both **encoding** (compression) and **decoding** (decompression)
* Tracks character frequencies and constructs optimal binary codes
* Reduces file size while maintaining original data fidelity

### 📈 How It Works

1. Calculate the frequency of each character in the input file.
2. Build a min-heap of all characters (nodes) based on their frequency.
3. Build a Huffman Tree using greedy selection of lowest-frequency nodes.
4. Generate Huffman Codes and encode the input.
5. Store the Huffman Tree (or frequency map) along with encoded data.
6. Decode the file using the same tree structure.

### 🧠 Algorithm Used

* **Huffman Encoding** (Greedy Algorithm)

### 📂 Folder Structure (Example)

```
FileZipper/
│
├── huffman.cpp          # Main encoder/decoder logic
├── input.txt            # Input file to be compressed
├── encoded.bin          # Compressed file
├── decoded.txt          # Output after decoding
└── README.md
```

### 🏁 Getting Started

To compile and run:

```bash
g++ huffman.cpp -o filezipper
./filezipper
```

### 📝 Use Cases

* Text file compression
* Reducing data storage or transmission costs
* Understanding greedy algorithm applications in real-world systems

---
### How to run:
1. Copy and paste into a .cpp file (e.g., filezipper.cpp
2. Compile: g++ filezipper.cpp -o filezipper
3. Run: ./filezipper
4. Input any string you want to compress.


### What this code does:
1. Reads input text.
2. Calculates frequency of each character.
3. Builds Huffman Tree using a min-heap.
4. Generates Huffman codes for each character.
5. Encodes the text to a binary string.
6. Decodes it back to original text.
7. Prints codes, encoded string, and decoded string.
