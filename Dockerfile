FROM i386/alpine:latest

ENV CC=clang

WORKDIR /cos

RUN mkdir ./build

COPY ./src ./src

COPY ./scripts ./scripts

RUN apk update

RUN apk --no-cache add \
  clang \
  lld \
  musl-dev \
  libc-dev \
  binutils \
  compiler-rt \
  compiler-rt-static

CMD ["tail", "-f", "/dev/null"]
