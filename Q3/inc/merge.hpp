#pragma once

/**
 * @brief 
 * 
 * Returns a new Container containing the copied contents
 * of con1 and con2
 * 
 * @param Container*&con1
 * @param Container*&con2
 * 
 * @return template <class Container> Container
 */
template <class Container>
Container merge(Container*&con1,Container*&con2)
{
    Container res;
    auto con1End = con1->end();
    auto con2End = con2->end();
    for(auto it = con1->begin(); it != con1End; ++it)
    {
        res.push_back(*it);
    }
    for(auto it = con2->begin(); it != con2End; ++it)
    {
        res.push_back(*it);
    }
    return res;
}