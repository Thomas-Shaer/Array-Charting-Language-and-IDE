#include "screenshot.h"

#include "stb_image_write.h"



ImageBuf::ImageBuf() { Width = Height = 0; Data = NULL; }
ImageBuf::~ImageBuf() { Clear(); }
void ImageBuf::Clear() { if (Data) free(Data); Data = NULL; }

void ImageBuf::CreateEmpty(int w, int h)
{
    Clear();
    Width = w;
    Height = h;
    Data = (u32*)malloc(Width * Height * 4);
    memset(Data, 0, Width * Height * 4);
}

void ImageBuf::CreateFromCaptureGL(int x, int y, int w, int h)
{
    Clear();
    Width = w;
    Height = h;
    Data = (u32*)malloc(Width * Height * 4);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, Data);
    RemoveAlpha();
}

void ImageBuf::SaveFile(const char* filename)
{
    stbi_write_png(filename, Width, Height, 4, Data, Width * 4);
}

void ImageBuf::RemoveAlpha()
{
    u32* p = Data;
    int n = Width * Height;
    while (n-- > 0)
    {
        *p |= 0xFF000000;
        p++;
    }
}

void ImageBuf::BlitTo(ImageBuf* dst, int src_x, int src_y, int dst_x, int dst_y, int w, int h)
{
    ImageBuf* src = this;
    IM_ASSERT(dst != src);
    IM_ASSERT(dst != NULL);
    IM_ASSERT(src_x >= 0 && src_y >= 0);
    IM_ASSERT(src_x + w <= src->Width);
    IM_ASSERT(src_y + h <= src->Height);
    IM_ASSERT(dst_x >= 0 && dst_y >= 0);
    IM_ASSERT(dst_x + w <= dst->Width);
    IM_ASSERT(dst_y + h <= dst->Height);
    for (int y = 0; y < h; y++)
        memcpy(dst->Data + dst_x + (dst_y + y) * dst->Width, src->Data + src_x + (src_y + y) * src->Width, w * 4);
}

void ImageBuf::FlipVertical()
{
    int comp = 4;
    int stride = Width * comp;
    unsigned char* line_tmp = new unsigned char[stride];
    unsigned char* line_a = (unsigned char*)Data;
    unsigned char* line_b = (unsigned char*)Data + (stride * (Height - 1));
    while (line_a < line_b)
    {
        memcpy(line_tmp, line_a, stride);
        memcpy(line_a, line_b, stride);
        memcpy(line_b, line_tmp, stride);
        line_a += stride;
        line_b -= stride;
    }
    delete[] line_tmp;
}
ImageBuf::u32* ImageBuf::GetPtr(int x, int y)
{
    return &Data[x + y * Width];
}
ImageBuf::u32 ImageBuf::GetPixel(int x, int y) const
{
    return Data[x + y * Width];
}




void ImageBuf::capture(int x, int y, int width, int height, const std::string& fileName ) {
    ImageBuf  Output;
    // Capture immediately
    ImGuiIO& io = ImGui::GetIO();
    Output.CreateFromCaptureGL(x, io.DisplaySize.y - y - height, width, height);
    Output.FlipVertical();
    if (Output.Data)
        Output.SaveFile(fileName.c_str());
    return;

}