#ifndef METABALLS_H
#define METABALLS_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>

class Metaballs : public QOpenGLWidget
{
    Q_OBJECT

public:
    Metaballs(QWidget *parent = nullptr);
    ~Metaballs();

protected:
    void initializeGL() override;
    void paintGL() override;

private:
    QOpenGLShaderProgram *m_shaderProgram;
};

#endif // METABALLS_H
