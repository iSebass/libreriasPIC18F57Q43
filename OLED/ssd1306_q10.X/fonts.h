
#ifndef FONTS_H
#define	FONTS_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "ssd1306_conf.h"
#include "stdint.h"

typedef struct {
    const uint8_t FontWidth;    /*!< Font width in pixels */
    uint8_t FontHeight;   /*!< Font height in pixels */
    const uint16_t *data; /*!< Pointer to data font data array */
} FontDef;

extern FontDef Font_7x10;

#endif	/* XC_HEADER_TEMPLATE_H */

