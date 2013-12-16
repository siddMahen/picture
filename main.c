#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <picam.h>

int main(int agrc, char** argv){
	int width, height;
	
	width = atoi(argv[1]);
	height = atoi(argv[2]);

	FILE *file = fopen("picture.jpeg", "w+");

	long len = 0;

	PicamParams prms;
	prms.exposure = 1;
	prms.meterMode = 1;
	prms.imageFX = 0;
	prms.awbMode = 1;
	prms.ISO = 0;
	prms.sharpness = 10;
	prms.contrast = 20;
	prms.brightness = 65;
	prms.saturation = 0;
	prms.videoStabilisation = 1;
	prms.exposureCompensation = 1;
	prms.rotation = 0;
	prms.hflip = 0;
	prms.vflip = 0;
	prms.shutter_speed = 0;
	prms.videoProfile = 0;
	prms.videoBitrate = 17000000;
	prms.videoFramerate = 30;
	prms.quantisationParameter = 0;
	prms.inlineHeaders = 0;

	char *img = (char *)takePhotoWithDetails(height, width, 85, &prms, &len);

	printf("Took a picture!\n");

	fwrite(img, 1, len, file);
	fclose(file);
	return 0;
}
