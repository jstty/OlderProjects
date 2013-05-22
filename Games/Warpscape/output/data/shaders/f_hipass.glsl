uniform sampler2D source;
uniform float glow;

void main(void)
{
   vec4 color = texture2D(source, gl_TexCoord[0].st);

   color.x = color.x > glow ? color.x : 0.0;
   color.y = color.y > glow ? color.y : 0.0;
   color.z = color.z > glow ? color.z : 0.0;

   color.x = color.x > 1.0 ? 1.0 : color.x;
   color.y = color.y > 1.0 ? 1.0 : color.y;
   color.z = color.z > 1.0 ? 1.0 : color.z;

   gl_FragColor = color;
}
