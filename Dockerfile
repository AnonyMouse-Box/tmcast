FROM gcc:latest AS compiler
RUN ["mkdir", "-p", "/usr/dev"]
WORKDIR /usr/dev
COPY src src
COPY inc inc
COPY lib lib
COPY makefile .
CMD ["make"]

#FROM alpine:latest AS testbed
#COPY --from=0 /usr/build/binary /usr/local/bin/
#CMD ["/usr/local/bin/binary", "test"]
