#include <stdio.h>
#include "../inc/print.h"
#include "../inc/structures.h"
#include "../inc/utils.h"
#include "../inc/scene.h"
#include "../inc/trace.h"

int	main(void)
{
    int     i;
    int     j;
    double      u;
    double      v;

    int     canvas_width;
    int     canvas_height;
	t_color3	pixel_color;
    t_canvas    canv;
    t_camera    cam;
    t_ray       ray;
	t_object	*world;
	t_sphere	sp;

    //Scene setting;
    canv = canvas(400, 300);
    cam = camera(&canv, point3(0, 0, 0));
	world = object(SP, sphere(point3(-2, 0, -5), 2));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2)));
	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 990)));

    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    printf("P3\n%d %d\n255\n", canv.width, canv.height);
    j = canv.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < canv.width)
        {
            u = (double)i / (canv.width - 1);
            v = (double)j / (canv.height - 1);
            //ray from camera origin to pixel
            ray = ray_primary(&cam, u, v);
            pixel_color = ray_color(&ray, world);
        /* * * * 수정 끝 * * * */
            write_color(pixel_color);
            ++i;
        }
    	--j;
    }
    return (0);
}
