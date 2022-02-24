// Constant Macros
#define LIFECAM_HORIZ_FOV 61
#define LIFECAM_VERT_FOV 34.3
#define LIFECAM_DIAG_FOV 68.5
// Macro Functions
#define FIND_FOV(dy, dz) (2(tan(0.5*dy)/dz)) // FOV of the of he object
#define FIND_PITCH_FROM_OBJECT(ay, vfov) ((ay/2) * vfov) // Vertical
#define FIND_YAW_FROM_OBJECT(ax, hfov) ((ax/2) * hfov) // Horizontal
#define FIND_DIST(ht, hc, ac, po) ((ht - hc) / (tan(ac + po))) // Distance from object
// Defines just cause (we need them) B)
#define VISION_TEST