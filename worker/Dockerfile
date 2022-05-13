################### Use Mallob
FROM pkis-base AS builder
USER root

################### Extract Mallob in run stage
FROM satcomp-base:worker AS pkis_liaison
WORKDIR /
# Copy pkis
COPY --from=builder /pkis/pkis pkis
COPY --chown=ecs-user /worker /competition

RUN chmod +x /competition/worker
