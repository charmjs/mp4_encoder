mkdir -p dist
emcc main.c lib/libx264.a lib/libavcodec.a lib/libavutil.a lib/libavformat.a -I include -o dist/index.html -Os
