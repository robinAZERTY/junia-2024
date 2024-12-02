class Element {
    public:
        Element() = default;
        virtual ~Element() = default;
    private :
        double x_, y_, collision_radius_;
};
