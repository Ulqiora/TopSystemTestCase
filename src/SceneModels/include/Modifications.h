#pragma once
struct Rotate{
    using Angle = float;
    Angle x,y,z;
};
struct Position{
    using SizeShift = float;
    SizeShift x,y,z;
};
struct Scale{
    using Size = float;
    Size x,y,z;
};
