FROM gcc:latest
COPY ./src .
WORKDIR ./src
RUN gcc -o tmcast tmcast.c
CMD ["./tmcast"]
