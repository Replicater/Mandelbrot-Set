#ifndef __CRAZYFISH_BITMAP__
#define __CRAZYFISH_BITMAP__

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef int LONG;

typedef struct tagBITMAPFILEHEADER
{
  WORD  bfType;
  DWORD bfSize;
  WORD  bfReserved1;
  WORD  bfReserved2;
  DWORD bfOffBits;
} __attribute__((packed)) BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
  DWORD        biSize;
  LONG         biWidth;
  LONG         biHeight;
  WORD         biPlanes;
  WORD         biBitCount;
  DWORD        biCompression;
  DWORD        biSizeImage;
  LONG         biXPelsPerMeter; /**< X分辨率*/
  LONG         biYPelsPerMeter; /**< Y分辨率*/
  DWORD        biClrUsed;       /**< 使用的颜色数，真彩色是0. */
  DWORD        biClrImportant;
} __attribute__((packed)) BITMAPINFOHEADER;

typedef struct {
  DWORD        bV5Size;
  LONG         bV5Width;
  LONG         bV5Height;
  WORD         bV5Planes;
  WORD         bV5BitCount;
  DWORD        bV5Compression;
  DWORD        bV5SizeImage;
  LONG         bV5XPelsPerMeter;
  LONG         bV5YPelsPerMeter;
  DWORD        bV5ClrUsed;
  DWORD        bV5ClrImportant;
  DWORD        bV5RedMask;
  DWORD        bV5GreenMask;
  DWORD        bV5BlueMask;
  DWORD        bV5AlphaMask;
  DWORD        bV5CSType;
	//  CIEXYZTRIPLE bV5Endpoints;
  DWORD        bV5GammaRed;
  DWORD        bV5GammaGreen;
  DWORD        bV5GammaBlue;
  DWORD        bV5Intent;
  DWORD        bV5ProfileData;
  DWORD        bV5ProfileSize;
  DWORD        bV5Reserved;
} __attribute__((packed)) BITMAPV5HEADER;

void build_bmp(char * _file,
			   int _w,
			   int _h,
			   char *_image);


void build_bmp(char * _file,
         int _w,
         int _h,
         char *_image)
{
  int width = _w;
  int height = _h;
  FILE * fp;

  // std::ofstream outFile(_file.c_str(), std::ios::binary);
  fp = fopen(_file, "w+b");

  BITMAPFILEHEADER bmpFileHeader;
  BITMAPINFOHEADER bmpInfoHeader;
  bmpInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
  bmpInfoHeader.biWidth = width;
  bmpInfoHeader.biHeight = height;
  bmpInfoHeader.biPlanes = 1;
  bmpInfoHeader.biBitCount = 24;
  // bmpInfoHeader.biBitCount = 1;
  bmpInfoHeader.biCompression = 0;
  bmpInfoHeader.biSizeImage = width * height * 3;
  // bmpInfoHeader.biSizeImage = width * height;
  bmpInfoHeader.biXPelsPerMeter = 2834;
  bmpInfoHeader.biYPelsPerMeter = 2834;
  bmpInfoHeader.biClrUsed = 2;
  bmpInfoHeader.biClrImportant = 0;

  ((char*)(&bmpFileHeader.bfType))[0] = 'B';
  ((char*)(&bmpFileHeader.bfType))[1] = 'M';
  bmpFileHeader.bfReserved1 = 0;
  bmpFileHeader.bfReserved2 = 0;
  bmpFileHeader.bfOffBits = bmpInfoHeader.biSize + sizeof(BITMAPFILEHEADER);
  bmpFileHeader.bfSize = bmpFileHeader.bfOffBits + bmpInfoHeader.biSizeImage;

  fwrite(&bmpFileHeader, sizeof(bmpFileHeader), 1, fp);
  fwrite(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, fp);
  // outFile.write(reinterpret_cast<char*>(&bmpFileHeader), sizeof(BITMAPFILEHEADER));
  // outFile.write(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(BITMAPINFOHEADER));

  // char *cache = new char[bmpInfoHeader.biSizeImage];

  // for (int j = 0; j < height; j++)
  //  for (int i = 0; i < width; i++)
  //  {
  //    int pos = j * width + i;
  //    cache[pos * 3] = 0;
  //    cache[pos * 3 + 1] = 0;
  //    cache[pos * 3 + 2] = 255;
  //  }

  fwrite(_image, bmpInfoHeader.biSizeImage, 1, fp);
  // outFile.write(_image, bmpInfoHeader.biSizeImage);

  fclose(fp);
};


#else

/// Do nothing.

#endif
