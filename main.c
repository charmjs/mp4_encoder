#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <stdio.h>

#include <emscripten.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} ImageData;

typedef struct {
    uint8_t *prt;
    size_t size;
} BufferData;

EMSCRIPTEN_KEEPALIVE
/* BufferData *createVideo(ImageData **imageList, size_t imageNumber, uint32_t seconds) { */
void createVideo() {
    const AVCodec *codec;
    AVCodecContext *c = NULL;
    FILE *f;
    AVFrame *frame;
    AVPacket *pkt;

    codec = avcodec_find_encoder(AV_CODEC_ID_H264);
    if (!codec) {
        fprintf(stderr, "H264 codec not found\n");
        exit(1);
    }

    c = avcodec_alloc_context3(codec);
    if(!c) {
        fprintf(stderr, "Couldn't allocate video codec context\n");
        exit(1);
    }

    pkt = av_packet_alloc();
    if (!pkt) {
        exit(1);
    }

    c->bit_rate = 400000;
    c->width = 1280;
    c->height = 720;
    c->time_base = (AVRational){1, 1};
    c->framerate = (AVRational){1, 1};

    printf("Done, prt: $d", &c);
}