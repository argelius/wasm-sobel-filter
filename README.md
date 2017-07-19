# wasm-sobel-filter

Comparison between JS and WASM implementations of Sobel filter. This demo requires a browser that can execute [Web Assembly](http://webassembly.org/).

## Usage

Run a web server in the root of this repo and open with a web browser.

## Compilation

There is a C implementation of a Sobel filter. You can compile it to WASM using [Emscripten](https://github.com/kripken/emscripten).

```bash
emcc -o sobel.js sobel.c -lm -O3 -s WASM=1 -s EXPORTED_FUNCTIONS="['_sobel']"
```
