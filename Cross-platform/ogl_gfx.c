#include "ogl_func.h"
#include "ogl_gfx.h"

void draw_scene() {
  glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  GLuint shader_prog = load_shader();
  GLuint v_array_obj = load_vertex();

  glUseProgram(shader_prog);
  glBindVertexArray(v_array_obj);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

GLuint load_shader() {
  const char* v_shader_src =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\n\0";
  const char* f_shader_src =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "void main()\n"
      "{\n"
      "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
      "}\n\0";

  GLuint v_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(v_shader, 1, &v_shader_src, NULL);
  glCompileShader(v_shader);

  GLuint f_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(f_shader, 1, &f_shader_src, NULL);
  glCompileShader(f_shader);

  GLuint shader_prog = glCreateProgram();
  glAttachShader(shader_prog, v_shader);
  glAttachShader(shader_prog, f_shader);
  glLinkProgram(shader_prog);

  glDeleteShader(v_shader);
  glDeleteShader(f_shader);

  return shader_prog;
}

GLuint load_vertex() {
  float vertices[] = {
      -0.5f, -0.5f, 0.0f,  // left
      0.5f,  -0.5f, 0.0f,  // right
      0.0f,  0.5f,  0.0f   // top
  };

  GLuint v_buffer_obj, v_array_obj;
  glGenVertexArrays(1, &v_array_obj);
  glGenBuffers(1, &v_buffer_obj);

  glBindVertexArray(v_array_obj);

  glBindBuffer(GL_ARRAY_BUFFER, v_buffer_obj);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);

  return v_array_obj;
}