## Fractal Image Generator

> This project uses [utest.h](https://github.com/sheredom/utest.h) as a Git submodule for unit testing.

A fractal image generator implemented in C, supporting multiple classic fractal algorithms and saving generated images in PGM format.

```
fractal-project/
├── .github/workflows/     
│   └── build.yml
├── src/                  
│   ├── main.c           
│   ├── image.h/.c        # Image processing module
│   └── fractal.h/.c      # Fractal algorithms module
├── YY.utest/             # Unit test framework
│   └── utest.h
├── CMakeLists.txt        # CMake build configuration
└── README.md             
```

###  Features

- **Three Classic Fractal Algorithms**
  - Mandelbrot Set
  - Sierpinski Carpet
  - Julia Set
-  **Image Output**
  - Binary PGM format (P5)
  - Optional ASCII PGM format for debugging
  - 8-bit grayscale images

