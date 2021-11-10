#ifndef GEOMETRY_SPHERE_H
#define GEOMETRY_SPHERE_H

#include<GLFW/glfw3.h>
#include <vector>
#include <MathTools/Vector3D.h>
/// <summary>
/// A sphere built with triangles.
/// Visit : http://www.songho.ca/opengl/gl_sphere.html for more details.
/// </summary>
class Sphere
{
public:
    // ctor/dtor
    
    /// <summary>
    /// Constructor of a Sphere.
    /// </summary>
    /// <param name="radius">float : radius of the sphere</param>
    /// <param name="position">Vector3D* : position of the center</param>
    /// <param name="color">Vector3D* : color RGB (between 0 and 1) of the sphere</param>
    /// <param name="sectorCount">int : number of sectors (horizontal "lines" of edges)</param>
    /// <param name="stackCount">int : number of stack (vertical "lines" of edges)</param>
    /// <param name="smooth">bool : if vertices has to be smooth or not</param>
    Sphere(float radius=1.0f, Vector3D* position = new Vector3D(), Vector3D* color = new Vector3D(1,1,1), int sectorCount=12, int stackCount=6, bool smooth=true);
    ~Sphere();

    // Getters and setters
    float getRadius() const                         { return radius; }
    int getSectorCount() const                      { return sectorCount; }
    int getStackCount() const                       { return stackCount; }
    Vector3D* getPosition() const                    { return position; }
    void set(float radius, int sectorCount, int stackCount, bool smooth=true);
    void setRadius(float radius);
    void setSectorCount(int sectorCount);
    void setStackCount(int stackCount);
    void setSmooth(bool smooth);
    void setPosition(Vector3D position);
    void setColor(Vector3D color);

    // Getters for vertex data
    unsigned int getVertexCount() const             { return (unsigned int)vertices.size() / 3; }
    unsigned int getNormalCount() const             { return (unsigned int)normals.size() / 3; }
    unsigned int getTexCoordCount() const           { return (unsigned int)texCoords.size() / 2; }
    unsigned int getIndexCount() const              { return (unsigned int)indices.size(); }
    unsigned int getLineIndexCount() const          { return (unsigned int)lineIndices.size(); }
    unsigned int getTriangleCount() const           { return getIndexCount() / 3; }
    unsigned int getVertexSize() const              { return (unsigned int)vertices.size() * sizeof(float); }
    unsigned int getNormalSize() const              { return (unsigned int)normals.size() * sizeof(float); }
    unsigned int getTexCoordSize() const            { return (unsigned int)texCoords.size() * sizeof(float); }
    unsigned int getIndexSize() const               { return (unsigned int)indices.size() * sizeof(unsigned int); }
    unsigned int getLineIndexSize() const           { return (unsigned int)lineIndices.size() * sizeof(unsigned int); }
    const float* getVertices() const                { return vertices.data(); }
    const float* getNormals() const                 { return normals.data(); }
    const float* getTexCoords() const               { return texCoords.data(); }
    const unsigned int* getIndices() const          { return indices.data(); }
    const unsigned int* getLineIndices() const      { return lineIndices.data(); }

    // Format to GL data
    
    /// <summary>
    /// Update the vertices and their colors for OpenGL.
    /// Ex : vx, vy, vz, r, g, b, v2x, v2y, v2z, r, g, b
    /// </summary>
    void updateGLVerticesColor();
    /// <summary>
    /// Generate indices for OpenGL
    /// </summary>
    void generateGLIndices();

    /// <summary>
    /// Returns vertices and their colors to be used in a Vertex Buffer Object
    /// </summary>
    /// <returns>GLfloat* : list of vertices coordinates and colors rgb values</returns>
    GLfloat* getGLVerticesColor() const             { return glVerticesColor; }
    /// <summary>
    /// Returns indices to be used in a Element Buffer Object
    /// </summary>
    /// <returns>GLuint* : list of indices</returns>
    GLuint* getGLIndices() const                    { return glIndices;}

    // for interleaved vertices: V/N/T
    unsigned int getInterleavedVertexCount() const  { return getVertexCount(); }    // # of vertices
    unsigned int getInterleavedVertexSize() const   { return (unsigned int)interleavedVertices.size() * sizeof(float); }    // # of bytes
    int getInterleavedStride() const                { return interleavedStride; }   // should be 32 bytes
    const float* getInterleavedVertices() const     { return interleavedVertices.data(); }

    // debug
    void printSelf() const;

protected:

private:
    // member functions
    void buildVerticesSmooth();
    void buildVerticesFlat();
    void buildInterleavedVertices();
    void clearArrays();
    void addVertex(float x, float y, float z);
    void addNormal(float x, float y, float z);
    void addTexCoord(float s, float t);
    void addIndices(unsigned int i1, unsigned int i2, unsigned int i3);
    std::vector<float> computeFaceNormal(float x1, float y1, float z1,
                                         float x2, float y2, float z2,
                                         float x3, float y3, float z3);

    // memeber vars
    float radius;
    int sectorCount;                        // longitude, # of slices
    int stackCount;                         // latitude, # of stacks
    bool smooth;
    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<float> texCoords;
    std::vector<unsigned int> indices;
    std::vector<unsigned int> lineIndices;
    

    // Display attributes 

    // Vertices coordinates and color RGB values for VBO
    GLfloat* glVerticesColor;
    // Indices of the triangles of the sphere
    GLuint* glIndices;
    // Position of the center of the sphere
    Vector3D* position;
    // Color RGB of the sphere
    Vector3D* color;

    // interleaved
    std::vector<float> interleavedVertices;
    int interleavedStride;                  // # of bytes to hop to the next vertex (should be 32 bytes)

};

#endif
