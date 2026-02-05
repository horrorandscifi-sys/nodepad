import Fastify from 'fastify';
const native = require('../build/Release/high_load_engine');

const fastify = Fastify({ logger: true });

fastify.post('/compute', async (request, reply) => {
    const { data } = request.body as { data: number[] };

    return new Promise((resolve) => {
        native.process(data, (err: Error, result: number) => {
            resolve({ result, compute_time: "calculated_in_cpp" });
        });
    });
});

fastify.listen({ port: 3000, host: '0.0.0.0' });
