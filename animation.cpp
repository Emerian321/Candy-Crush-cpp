#include "animation.h"

//contsructor
Animation::Animation(Rectangle *recToAnimate, AnimationType animationType)
      : rec{recToAnimate}, animationType{animationType} {}

void Animation::draw() {
  ++time;
  Translation t3{currentTranslation()};
  Rotation r{rec->getCenter(), currentRotation()};
  rec->draw();
}

Point Animation::currentTranslation() {
    if (animationType==bounce || animationType == spinAndBounce)
        return {0, static_cast<int>(-1*bounceHeight*sin(3.1415*time/animationTime))};
    else
        return {0, 0};
}

double Animation::currentRotation() {
    if (animationType==spin || animationType == spinAndBounce)
      return time*360.0/animationTime;
    else
      return 0;
  }