// int x,y;
// double floorPointDistance;
// for(int i = floorCastingStartPixel; i < planeHeight; i++) {
// floorPointDistance = ( ( PLAYERHEIGHT * playerPaneDist ) / ( (planeHeight>>1) - i ) ) / (Math.sin(((double)toRad(angle+rayAngle))));

// // almost good
// x = (int) Math.abs( (-floorPointDistance * sinTable[rayAngle]) + (playerX) ) % 64;
// y = (int) Math.abs( (floorPointDistance * cosTable[rayAngle]) + (playerY) ) % 64;

// screenBuffer.setRGB(raysCasted, i, Texture.floor.texture.getRGB(x,y));
// }


// int floorCastingStartPixel = planeHeight>>1;
// int x,y;
// for (int i=floorCastingStartPixel; i<=planeHeight-1; i++) {
// distance = (float) (((float)PLAYERHEIGHT / (i-(planeHeight>>1)) )* playerPaneDist );

// x = ( (int) (distance * (cosTable[rayAngle])) ) + playerX;
// y = ( (int) (distance * (sinTable[rayAngle])) ) + playerY;

// screenBuffer.setRGB(raysCasted, i, addFogEffect(Texture.floor.texture.getRGB(x&63,y&63),distance));
// }






// /* this is how to find rayangle */
// 3	float column_angle = atan( (float) ( column - (SCREEN_WIDTH/2) ) / SCREEN_HEIGHT);
// 4	float rayangle = player.angle+column_angle;
// 5	/**/      
// 6	 
// 7	for (int row=bot; row<=SCREEN_H-1; ++row)
// 8	{
// 9	distance = ((float)PLAYER_HEIGHT / (row-SCREEN_H/2) )* PROJ_PLANE * cos_column_angle;
// 10	      
// 11	x = -distance * (sin_rayangle);
// 12	y = distance * (cos_rayangle);
// 13	 
// 14	x+=player.x;
// 15	y+=player.y;
// 16	      
// 17	tile = map.floor[x>>6][y>>6].tile;
// 18	 
// 19	/* Might need this - it will crash if 'tile' is out of bounds  
// 20	if(x>=MAP_WIDTH*64 || x<0) tile = 2;
// 21	if(y>=MAP_HEIGHT*64 || y<0) tile = 2;
// 22	*/
// 23	    
// 24	 putpixel(buf,column,row,getpixel(tex,x&63,y&63);
// 25
// 26
// 27	}

#include <stdio.h>

int main()
{
    // for(float i = 150; i < 200; i++)
        // printf("%f::%f\n", i - 100, 32 / (i - 100) * 277);
        printf("%d\n", (32 / (191 - 100) * 277) / 1);
        printf("%f\n", (32.0 / (191.0 - 100.0) * 277.0) / 1.0);
    return (0);
}
