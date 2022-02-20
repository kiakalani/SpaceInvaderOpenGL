#version 330 core
in vec2 vertex;
in vec2 uv;

out vec2 uv_coords;

uniform mat4 camera_matrix;
uniform mat4 transformation_matrix;

void main()
{
    uv_coords = vec2(uv.x, 1.0 - uv.y);
    gl_Position = camera_matrix * transformation_matrix * vec4(vertex.x, vertex.y, 0.0, 1.0);
}
