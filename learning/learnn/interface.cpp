# include <iostream>
/*
The Irenderer is a simple interface that defines the methods that must be implemented by the derived classes.
an interf
*/
class IRenderer
{
    public:
        // virtual void update() { std::cout << "IRenderer::update()" << std::endl; }
        // virtual void draw() { std::cout << "IRenderer::draw()" << std::endl; }
    // but it does not make sense to have a default implementation for these methods
    // because OpenGL and Vulkan are actually graphics APIs that do something 
    // and i just want my Irenderer to serve as a common interface or sort of a template for what must be implemented in the derived classes(OpenGL and Vulkan)
    // so i will make these methods pure virtual = 0
    // and now i cannot instantiate the IRenderer class because it has pure virtual methods, and those methods must be implemented or overriden in the derived classes
        virtual void update() = 0;
        virtual void draw() = 0;

};

class OpenGL : public IRenderer
{
    public:
        void draw() override { std::cout << "OpenGL::draw()" << std::endl; }
        void update() override { std::cout << "OpenGL::update()" << std::endl; }   
};

class Vulkan : public IRenderer
{
    public:
        void draw() override { std::cout << "Vulkan::draw()" << std::endl; }
        void update() override { std::cout << "Vulkan::update()" << std::endl; }
};

class DirectX : public IRenderer
{
    public:
        void draw() override { std::cout << "DirectX::draw()" << std::endl; }
        void update() override { std::cout << "DirectX::update()" << std::endl; }
};

int main()
{
    IRenderer* renderer = new Vulkan();
    renderer->update();
    renderer->draw();
    /* well now i actually want to use OpenGL */
    // this is the advantage of using a common interface
    delete renderer;
    renderer = new OpenGL();
    renderer->update();
    renderer->draw();
    
    delete renderer;
    return 0;
}