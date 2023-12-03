#pragma once
namespace Modify{
struct Rotate{
    using Angle = double;
    Angle x,y;
};
struct Position{
    using SizeShift = double;
    SizeShift x,y;
};
struct Scale{
    using Size = double;
    Size x,y;
};
}
