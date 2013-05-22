uniform sampler2D p[4];
uniform sampler2D source;

void main(void)
{
   vec4    color = texture2D(p[0],   gl_TexCoord[0].st);
   color = color + texture2D(p[1],   gl_TexCoord[0].st);
   color = color + texture2D(p[2],   gl_TexCoord[0].st);
   color = color + texture2D(p[3],   gl_TexCoord[0].st);
   color = color + texture2D(source, gl_TexCoord[0].st);
    
   gl_FragColor = color;
}
