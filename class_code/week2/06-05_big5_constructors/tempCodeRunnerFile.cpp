        Entity(const Entity& other)//copy constuctor
        {
            cout<<"copy constructor called"<<endl;
            id_ = other.id_;
            data_ = other.data_;
        }