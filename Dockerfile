FROM ubuntu:18.04

RUN apt-get update -yqq
RUN apt-get install -yqq build-essential

COPY . /usr/src/app

WORKDIR /usr/src/app