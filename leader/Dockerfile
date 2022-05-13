################### Use Mallob
FROM pkis-base AS builder
USER root


################### Extract pkis in run stage
FROM satcomp-base:leader AS pkis_liaison
WORKDIR /
# Copy pkis and solver scripts
COPY --from=builder pkis/pkis pkis
COPY --chown=ecs-user /run_pkis.sh /competition
COPY --chown=ecs-user /solver /competition
USER ecs-user
RUN chmod +x /competition/run_pkis.sh
RUN chmod +x /competition/solver