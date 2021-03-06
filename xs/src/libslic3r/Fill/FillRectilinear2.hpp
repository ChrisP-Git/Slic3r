#ifndef slic3r_FillRectilinear2_hpp_
#define slic3r_FillRectilinear2_hpp_

#include "../libslic3r.h"

#include "FillBase.hpp"

namespace Slic3r {

class Surface;

class FillRectilinear2 : public Fill
{
public:
    virtual ~FillRectilinear2() {}
    virtual Polylines fill_surface(const Surface *surface, const FillParams &params);

protected:
	bool fill_surface_by_lines(const Surface *surface, const FillParams &params, float angleBase, float pattern_shift, Polylines &polylines_out);

	coord_t _min_spacing;
	coord_t _line_spacing;
	// distance threshold for allowing the horizontal infill lines to be connected into a continuous path
	coord_t _diagonal_distance;
};

class FillGrid2 : public FillRectilinear2
{
public:
    virtual ~FillGrid2() {}
    virtual Polylines fill_surface(const Surface *surface, const FillParams &params);

protected:
	// The grid fill will keep the angle constant between the layers, see the implementation of Slic3r::Fill::Base.
    virtual float _layer_angle(size_t idx) const { return 0.f; }
};

class FillTriangles : public FillRectilinear2
{
public:
    virtual ~FillTriangles() {}
    virtual Polylines fill_surface(const Surface *surface, const FillParams &params);

protected:
	// The grid fill will keep the angle constant between the layers, see the implementation of Slic3r::Fill::Base.
    virtual float _layer_angle(size_t idx) const { return 0.f; }
};

class FillCubic : public FillRectilinear2
{
public:
    virtual ~FillCubic() {}
    virtual Polylines fill_surface(const Surface *surface, const FillParams &params);

protected:
	// The grid fill will keep the angle constant between the layers, see the implementation of Slic3r::Fill::Base.
    virtual float _layer_angle(size_t idx) const { return 0.f; }
};


}; // namespace Slic3r

#endif // slic3r_FillRectilinear2_hpp_
