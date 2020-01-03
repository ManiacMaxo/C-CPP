#include <vector>
#include "airplanes.hpp"

class Airport {
    unsigned int max_planes;
    unsigned int max_plane_size;
    bool accepts_military;
    bool accepts_passenger;
    std::vector<Airplane> planes;
    double x;

   public:
    class LandPlaneError {};
    bool can_fit_plane(Airplane& plane) {
        if (max_planes < planes.size && plane.get_size() < max_plane_size) {
            if ((plane.get_military() && accepts_military) ||
                (!plane.get_military() && accepts_passenger)) {
                return 1;
            }
        }
        return 0;
    }
    void land_plane(Airplane const& plane) {
        if (!can_fit_plane) {
            throw LandPlaneError();
        }
        planes.push_back(plane);
    }
};
