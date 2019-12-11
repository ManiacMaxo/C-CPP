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
    bool can_fit_plane(Airplane const& plane) {
        if (max_planes < planes.size && plane.size < max_plane_size) {
            if ((plane.military && accepts_military) ||
                (!plane.military && accepts_passenger)) {
                return 1;
            }
        }
        return 0;
    }
    void land_plane(Airplane const& plane) {
        if (can_fit_plane) {
            planes.push_back(plane);
        }
    }
};
