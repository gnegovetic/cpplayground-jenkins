FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y cmake clang gdb

WORKDIR HelloWorld

