// SPDX-License-Identifier: MIT
// Copyright (c) 2020 The Pybricks Authors

#include <stdint.h>

#include <pbio/error.h>
#include <pbio/light_grid.h>

#include "animation.h"

#ifndef _PBIO_LIGHT_LIGHT_GRID_H_
#define _PBIO_LIGHT_LIGHT_GRID_H_

/** Implementation-specific callbacks for a light grid. */
typedef struct {
    /**
     * Sets the light at @p row, @p col to @p brightness.
     *
     * @param [in]  light_grid  The light grid instance.
     * @param [in]  row         The row index (0 to size-1).
     * @param [in]  col         The column index (0 to size-1).
     * @param [in]  brightess   The apparent brightness (0 to 100).
     * @return                  Success/failure of the operation.
     */
    pbio_error_t (*set_pixel)(pbio_light_grid_t *light_grid, uint8_t row, uint8_t col, uint8_t brightess);
} pbio_light_grid_funcs_t;

struct _pbio_light_grid_t {
    /** Animation instance for background animation. */
    pbio_light_animation_t animation;
    /** Implementation specific callback functions. */
    const pbio_light_grid_funcs_t *funcs;
    /** Animation cell data. */
    const uint8_t *animation_cells;
    /** The number of cells in @p animation_cells */
    uint8_t num_animation_cells;
    /** The index of the currently displayed animation cell. */
    uint8_t current_cell;
    /** Animation update rate in milliseconds. */
    uint16_t interval;
    /** Size of the grid (assumes grid is square) */
    uint8_t size;
};

void pbio_light_grid_init(pbio_light_grid_t *light_grid, uint8_t size, const pbio_light_grid_funcs_t *funcs);

#endif // _PBIO_LIGHT_LIGHT_GRID_H_
