#version 330 core

in vec2 uv_coords;

uniform sampler2D texture_add;
void main()
{
    vec4 pixel = texture(texture_add, uv_coords);
    //pixel = vec4(uv_coords.x, 0.0, uv_coords.y, 1.0);
    if (pixel.a < 0.5) discard;
    else
    gl_FragColor = pixel;
}