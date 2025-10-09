#include <stdlib.h>
#include <zephyr/kernel.h>
#include "animation.h"

LV_IMG_DECLARE(snake);
LV_IMG_DECLARE(crab);

const lv_img_dsc_t *anim_imgs[] = {
    &snake, &crab,
};

void draw_animation(lv_obj_t *canvas) {
#if IS_ENABLED(CONFIG_NICE_VIEW_CRITTERS_ANIMATION)
    lv_obj_t *art = lv_animimg_create(canvas);
    lv_obj_center(art);

    #if IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
        lv_img_set_src(art, anim_imgs[0]);
    #else
        lv_img_set_src(art, anim_imgs[1]);
    #endif
    // lv_animimg_set_duration(art, CONFIG_NICE_VIEW_CRITTERS_ANIMATION_MS);
    // lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
    // lv_animimg_start(art);
#else
    lv_obj_t *art = lv_img_create(canvas);

    int length = sizeof(anim_imgs) / sizeof(anim_imgs[0]);
    srand(k_uptime_get_32());
    int random_index = rand() % length;

    lv_img_set_src(art, anim_imgs[random_index]);
#endif

    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 36, 0);
}
