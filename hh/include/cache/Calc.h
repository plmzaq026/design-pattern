#ifndef CALC_H
#define CALC_H


class Calc
{
    public:
        Calc();
        virtual ~Calc();
        int cm2pixel(float cm)
        {
            return (int)(cm * CM_TO_PIXEL + 0.5);
        }
        float pixel2cm(int pixel)
        {
            return pixel * PIXEL_TO_CM;
        }
    private:
        float CM_TO_PIXEL = 28.35f;
        float PIXEL_TO_CM = 1 / 28.35f;
};

#endif // CALC_H
