#include "waves/interpolator.h"
#include <assert.h>


namespace
{
    class InterpolatorFunction : public WaveFunction
    {
        std::shared_ptr<Stream<double>> m_stream;
        unsigned m_sample_rate;
        double m_duration;

    public:
        InterpolatorFunction(std::shared_ptr<Stream<double>> stream, unsigned sample_rate)
            : m_stream(stream), m_sample_rate(sample_rate), m_duration((stream->size() - 1) / sample_rate) { }

        double duration() const override
        {
            return m_duration;
        }

        double operator [](double t) const override
        {
            assert(0 <= t);
            assert(t < duration());

            unsigned i = (unsigned)(t * m_sample_rate);
            unsigned j = i + 1;

            assert(i < m_stream->size());
            assert(j < m_stream->size());

            double dt = (t - double(i) / m_sample_rate) * m_sample_rate;

            assert(-0.00001 <= dt);
            assert(dt < 1.00001);

            double sample_at_i = (*m_stream)[i];
            double sample_at_j = (*m_stream)[j];

            return sample_at_i + (sample_at_j - sample_at_i) * dt;
        }
    };
}

Wave interpolate(std::shared_ptr<Stream<double>> samples, unsigned sample_rate)
{
    return Wave(std::make_shared<InterpolatorFunction>(samples, sample_rate));
}
