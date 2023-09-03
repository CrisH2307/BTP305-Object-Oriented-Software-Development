//! COMPOSITIONS, AGGREGATIONS AND ASSOCIATIONS
/*
+ Design collections of model objs
+ Distinguish Class Relationships with respect to ownership

_ The relationship between classes in OOP, aside from inheritance and parametic-polymorphism, exhibit different degrees of ownership.
These relationships include compositions, aggregations and associations. Each relationship reflects a different degrees of coupling
between calsses. 
+ A composition is a strong relationship: the composer obj owns the component obj
+ An aggregation is a weaker relationship: the aggregator has an instance of another class, which determines its own lifetime.
+ An association is the weakest relationship: one class accesses or uses another class: neither class exhibit a 'has a'
relationship to the other class
*/

//! Compositions
/*
_ A has-a relationship between classes, it implements complete ownership. The composer obj is responsible for destroying
its component objs at or before its own destruction. A composition is incomplete without its components
_  Design-wise, composition is more flexible(less coupled) than inheritance. Updates to the compinent class need
not affect the composer class. However, member functions added to the component class require forwarding memebr functions
in the composer class
*/


//! Aggregations
/*
_ Is a composition that doesn't manage the creation or destruction of the objs that it uses. The responsibility for creating
and destroying the objects lies outside the aggregator type. The aggregator is complete whether or not any of the objs that
it uses exist. The obj used survive the destruction of the aggregator
_ Degisn-wise, aggregation is more flexible (less coupled) than composition. Updates to any aggregaree type do not 
interfere with the design of the aggregator type. Member functions added to the aggregatee type do not require fowarding
member functions in the aggregator type.
*/

//! Assiciations
/*
_ Is a service relationship. It does not involve any ownership of one type by another. 
Each type is independent and complete without the related type.
_ Association is the least coupled relationship between classes. Member functions in an association do not require forwarding
member functions in the related type
*/