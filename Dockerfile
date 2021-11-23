FROM gcc:latest AS compiler
RUN ["mkdir -p /usr/src/tmcast"]
WORKDIR /usr/src/tmcast
COPY src .
COPY include .
COPY makefile .
ENTRYPOINT ["make"]

#FROM alpine:latest AS testbed
#COPY --from=0 /usr/src/tmcast/build/tmcast /usr/local/bin/
#ENTRYPOINT ["/usr/local/bin/tmcast", "test"]
