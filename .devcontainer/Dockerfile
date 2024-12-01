FROM docker.io/zmkfirmware/zmk-dev-arm:stable

ARG ZMK_URL
ARG ZMK_BRANCH
ARG ZMK_PATH

RUN git clone --filter=tree:0 --single-branch --branch=${ZMK_BRANCH} ${ZMK_URL} ${ZMK_PATH}

RUN cd ${ZMK_PATH} && \
    west init -l app/ && \
    west update && \
    cd /

COPY .bashrc tmp
RUN mv /tmp/.bashrc ~/.bashrc
