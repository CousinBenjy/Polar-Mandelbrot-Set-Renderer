#ifndef RENDERER_HPP_INCLUDED
#define RENDERER_HPP_INCLUDED

#include <vector>
#include <complex>
#include <memory>

// Class that handles rendering an instance of the fractal as a bitmap class

class renderer
{
    public:
        void generateFractal(int w, int h, double leftTheta, double rightTheta, double topR, double bottomR, uint64_t maxIterations);
        std::shared_ptr<uint32_t[]> renderBitmap(int w, int h, uint64_t maxIterations);

    private:
        // Represents the state of a pixel in the image after iterating it
        struct iterateState
        {
            std::complex<double> c;
            std::complex<double> zEnd;
            uint64_t iterations;
        };

        std::vector<iterateState> iterateResults;

        std::complex<double> mapNum(int x, int y, int w, int h, double leftTheta, double rightTheta, double topR, double bottomR);
        iterateState generateIterations(std::complex<double> c, uint64_t maxIterations);
};

#endif