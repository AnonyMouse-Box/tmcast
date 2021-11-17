FROM gcc:latest
COPY ./src .
COPY ./include .
WORKDIR ./src
RUN gcc -o tmcast tmcast.c
CMD ["./tmcast"]
