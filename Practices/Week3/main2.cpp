template<typename T>
Foo<T>::Foo : m_value{}
{
    m_data = "I am Foo"
    ++Foo<T>::m_cnt;
}

// specialize the default contructor
template<>
Foo<double>::Foo()
{
    m_value = 2.4;
    --Foo<double>::m_cnt;
}