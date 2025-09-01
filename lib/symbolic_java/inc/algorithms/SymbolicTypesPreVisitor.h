#ifndef _SYMBOLIC_TYPES_PREVISITOR_H_
#define _SYMBOLIC_TYPES_PREVISITOR_H_

#include <java/inc/java.h>

namespace columbus { namespace symbolic {

    class SymbolicTypesPreVisitor : public columbus::java::asg::Visitor {
    public:

        typedef struct TypesForSymbolic {
            enum TypeType {ARRAY_TYPE, CLASS_TYPE, METHOD_TYPE, PARAMETRIZED_TYPE, TYPE_VARIABLE, UNBOUNDED_WILDCARD_TYPE, UPPER_BOUNDED_WILDCARD_TYPE, LOWER_BOUNDED_WILDCARD_TYPE};
            columbus::NodeId  typeId;
            TypeType          typeType;

            union additional_informations {
                struct {
                    columbus::NodeId  componentTypeId;
                    unsigned int      arraySize;
                } ArrayType;

                struct {
                    columbus::NodeId  refersToId;
                    const string* refersToName;
                } ClassType;

                struct {
                    columbus::NodeId  returnTypeId;
                    unsigned int      parameterTypeSize;
                    unsigned int      thrownTypeSize;
                    columbus::NodeId  *parameterTypeIDs;
                    columbus::NodeId  *thrownTypeIDs;
                } MethodType;

                struct {
                    columbus::NodeId  rawTypeId;
                    unsigned int      argumentTypeSize;
                    columbus::NodeId  *argumentTypeIDs;
                } ParametrizedType;

                struct {
                    columbus::NodeId  refersToId;
                    unsigned int      boundTypeSize;
                    columbus::NodeId  *boundTypeIDs;
                } TypeVariable;

                struct {
                    columbus::NodeId  boundTypeId;
                } UnboundedWildcardType;

                struct {
                    columbus::NodeId  boundTypeId;
                } UpperBoundedWildcardType;

                struct {
                    columbus::NodeId  boundTypeId;
                } LowerBoundedWildcardType;
            } addInf;

            TypesForSymbolic() : typeId(0), typeType(ARRAY_TYPE) {
                addInf.MethodType.parameterTypeSize = 0;
                addInf.MethodType.thrownTypeSize = 0;
                addInf.ParametrizedType.argumentTypeSize = 0;
                addInf.TypeVariable.boundTypeSize = 0;
            }

        } TypesForSymbolic;

        typedef struct ClassForSymbolic {
            enum TypeType {CLASS, CLASS_GENERIC, ANONYMOUS_CLASS, ENUM, INTERFACE, INTERFACE_GENERIC};
            columbus::NodeId               classId;
			columbus::NodeId               typeId;
            TypeType                       classType;
            std::vector<columbus::NodeId>  memberMethodIDs;

            union additional_informations {
                // Class and AnonymousClass
                struct {
                    columbus::NodeId  superClassTypeId;
                    unsigned int      superInterfaceTypeSize;
                    columbus::NodeId  *superInterfaceTypeIDs;
                } Class;

                struct {
                    columbus::NodeId  superClassTypeId;
                    unsigned int      superInterfaceTypeSize;
                    unsigned int      typeParameterSize;
                    columbus::NodeId  *superInterfaceTypeIDs;
                    columbus::NodeId  *typeParameterIDs;
                } ClassGeneric;

                struct {
                    columbus::NodeId  superClassTypeId;
                    unsigned int      superInterfaceTypeSize;
                    columbus::NodeId  *superInterfaceTypeIDs;
                } Enum;

                struct {
                    unsigned int      superInterfaceTypeSize;
                    columbus::NodeId  *superInterfaceTypeIDs;
                } Interface;

                struct {
                    unsigned int      superInterfaceTypeSize;
                    unsigned int      typeParameterSize;
                    columbus::NodeId  *superInterfaceTypeIDs;
                    columbus::NodeId  *typeParameterIDs;
                } InterfaceGeneric;

            } addInf;

            ClassForSymbolic() : classId(0), classType(CLASS), memberMethodIDs() {
                addInf.Class.superInterfaceTypeSize = 0;
                addInf.ClassGeneric.superInterfaceTypeSize = 0;
                addInf.ClassGeneric.typeParameterSize = 0;
                addInf.Enum.superInterfaceTypeSize = 0;
                addInf.Interface.superInterfaceTypeSize = 0;
                addInf.InterfaceGeneric.superInterfaceTypeSize = 0;
                addInf.InterfaceGeneric.typeParameterSize = 0;
            }

        } ClassForSymbolic;

        // TODO: Annotation ???
        struct MethodForSymbolic {
            enum TypeType {METHOD, METHOD_GENERIC};
            columbus::NodeId               methodId;
            TypeType                       methodType;
            columbus::NodeId               methodTypeID;
            columbus::NodeId               classId;
            columbus::NodeId               returnTypeID;
            std::vector<columbus::NodeId>  parameterIDs;
            std::vector<columbus::NodeId>  thrownTypeIDs;
            std::vector<columbus::NodeId>  overridedByMethodIDs;
            std::vector<columbus::NodeId>  overridesMethodIDs;
            std::vector<columbus::NodeId>  typeParameterIDs;  // Only for MethodGeneric

            MethodForSymbolic() : methodId(0), methodType(METHOD), methodTypeID(0), classId(0), returnTypeID(0), parameterIDs(), thrownTypeIDs(), overridedByMethodIDs(), overridesMethodIDs(), typeParameterIDs() {}
        };

        struct TypesForSymbolic_compare {
            bool operator() (const TypesForSymbolic& l, const TypesForSymbolic& r) const {
                return l.typeId < r.typeId;
            }
        };

        struct ClassForSymbolic_compare {
            bool operator() (const ClassForSymbolic& l, const ClassForSymbolic& r) const {
                return l.classId < r.classId;
            }
        };

        struct MethodForSymbolic_compare {
            bool operator() (const MethodForSymbolic& l, const MethodForSymbolic& r) const {
                return l.methodId < r.methodId;
            }
        };

        typedef std::set<TypesForSymbolic, TypesForSymbolic_compare> TypesType;
        typedef std::set<ClassForSymbolic, ClassForSymbolic_compare> ClassesType;
        typedef std::set<MethodForSymbolic, MethodForSymbolic_compare> MethodType;

    private:
        static columbus::java::asg::Factory *m_asgFactory;

        // Primitive types
        static columbus::NodeId VOID_TYPE_ID;
        static columbus::NodeId CHAR_TYPE_ID;
        static columbus::NodeId BYTE_TYPE_ID;
        static columbus::NodeId SHORT_TYPE_ID;
        static columbus::NodeId INT_TYPE_ID;
        static columbus::NodeId LONG_TYPE_ID;
        static columbus::NodeId FLOAT_TYPE_ID;
        static columbus::NodeId DOUBLE_TYPE_ID;
        static columbus::NodeId BOOLEAN_TYPE_ID;
        static columbus::NodeId NULL_TYPE_ID;
        static columbus::NodeId ERROR_TYPE_ID;

        static columbus::NodeId OBJECT_TYPE_ID;

        // API Class types
        static columbus::NodeId OBJECT_CLASS_ID;
        static columbus::NodeId BOOLEAN_CLASS_ID;
        static columbus::NodeId CHARACTER_CLASS_ID;
        static columbus::NodeId BYTE_CLASS_ID;
        static columbus::NodeId SHORT_CLASS_ID;
        static columbus::NodeId INTEGER_CLASS_ID;
        static columbus::NodeId LONG_CLASS_ID;
        static columbus::NodeId STRING_CLASS_ID;

        static columbus::NodeId STRING_TYPE_ID;

        // NaN, Infinity
        static columbus::NodeId FLOAT_CLASS_ID;
        static columbus::NodeId DOUBLE_CLASS_ID;
        static columbus::NodeId FLOAT_NAN;
        static columbus::NodeId FLOAT_NEGATIVE_INFINITY;
        static columbus::NodeId FLOAT_POSITIVE_INFINITY;
        static columbus::NodeId DOUBLE_NAN;
        static columbus::NodeId DOUBLE_NEGATIVE_INFINITY;
        static columbus::NodeId DOUBLE_POSITIVE_INFINITY;

        // Containers
        static TypesType TYPES;
        static ClassesType CLASSES;
        static MethodType METHODS;

        // Overrides
        static std::map<columbus::NodeId, std::set<columbus::NodeId> > SUPER_CLASSES;

        static void visitClassMembers(columbus::NodeId classId, ClassForSymbolic *ct);
        static void visitMethods(columbus::NodeId methodId);
        static void calculateOverrides(const MethodForSymbolic& mt, NodeId methodId);
        static unsigned typePromotionPrecedence(NodeId type);

    public:
        SymbolicTypesPreVisitor(columbus::java::asg::Factory *factory);
        static void init();
        static void clean();

        // Visitors for type
        virtual void visit(const columbus::java::asg::type::ArrayType& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::type::ClassType& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::type::MethodType& n, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::type::ParameterizedType& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::type::TypeVariable& n, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::type::UnboundedWildcardType& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::type::UpperBoundedWildcardType& n, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::type::LowerBoundedWildcardType& n, bool callVirtualBase = true);

        // Visitors
        virtual void visit(const columbus::java::asg::struc::Class& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::ClassGeneric& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::Interface& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::InterfaceGeneric& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::AnonymousClass& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::Enum& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::Variable& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::Method& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::MethodGeneric& node, bool callVirtualBase = true);
        virtual void finishVisit();

        // Type related functions
        static TypesForSymbolic getType(const columbus::NodeId typeId);
        static columbus::NodeId getClassType(const columbus::NodeId refersToId);
        static columbus::NodeId getClassType(const string& refersToName);
        static columbus::NodeId getInterfaceType(const columbus::NodeId refersToId);
        static columbus::NodeId getClassId(const columbus::NodeId classTypeId);
        static columbus::NodeId getTypeVariable(const columbus::NodeId refersToId);
        static columbus::NodeId getUnboundedWildCardType(const columbus::NodeId boundTypeId);
        static columbus::NodeId getUpperBoundedWildCardType(const columbus::NodeId boundTypeId);
        static columbus::NodeId getLowerBoundedWildCardType(const columbus::NodeId boundTypeId);

        static columbus::NodeId mapPrimitiveTypeToBoxingType(const columbus::NodeId primitiveType);
        static bool isBoxingType(const columbus::NodeId typeId);
        static bool isBoxing(const columbus::NodeId classTypeId, const columbus::NodeId initValueTypeId, columbus::NodeId& toTypeId);
        static bool isPrimitiveType(const columbus::NodeId typeId);
        static bool isPrimitiveTypeExcpetNull(const columbus::NodeId typeId);
        static bool isPrimitiveNumericType(const columbus::NodeId typeId);
        static bool isReferenceType(const columbus::NodeId typeId);
        static bool isClassType(const columbus::NodeId typeId);
        static const MethodForSymbolic getOverridedBy(columbus::NodeId methodId);
        static columbus::NodeId getSuperClassId(const columbus::NodeId methodId);
        static std::set<columbus::NodeId> getSubTypes(const columbus::NodeId typeId);
        static std::set<columbus::NodeId> getSuperTypes(const columbus::NodeId typeId);
        static bool isSubType(const columbus::NodeId subTypeId, const columbus::NodeId superTypeId);
        static bool isSuperType(const columbus::NodeId superTypeId, const columbus::NodeId subTypeId);
        static bool isCastable(const columbus::NodeId sourceTypeId, const columbus::NodeId targetTypeId);

        static std::set<columbus::NodeId> getSuperClassTypeIDs(const columbus::NodeId forClassId);
        static std::set<columbus::NodeId> getSuperClassTypeIDsForTypeId(const columbus::NodeId typeId);

        inline static columbus::NodeId getVoidTypeId() {return VOID_TYPE_ID;}
        inline static columbus::NodeId getCharTypeId() {return CHAR_TYPE_ID;}
        inline static columbus::NodeId getByteTypeId() {return BYTE_TYPE_ID;}
        inline static columbus::NodeId getShortTypeId() {return SHORT_TYPE_ID;}
        inline static columbus::NodeId getIntTypeId() {return INT_TYPE_ID;}
        inline static columbus::NodeId getLongTypeId() {return LONG_TYPE_ID;}
        inline static columbus::NodeId getFloatTypeId() {return FLOAT_TYPE_ID;}
        inline static columbus::NodeId getDoubleTypeId() {return DOUBLE_TYPE_ID;}
        inline static columbus::NodeId getBooleanTypeId() {return BOOLEAN_TYPE_ID;}
        inline static columbus::NodeId getNullTypeId() {return NULL_TYPE_ID;}
        inline static columbus::NodeId getErrorTypeId() {return ERROR_TYPE_ID;}

        inline static columbus::NodeId getObjectTypeId() {return OBJECT_TYPE_ID;}

        inline static columbus::NodeId getBooleanClassId() {return BOOLEAN_CLASS_ID;}
        inline static columbus::NodeId getCharacterClassId() {return CHARACTER_CLASS_ID;}
        inline static columbus::NodeId getByteClassId() {return BYTE_CLASS_ID;}
        inline static columbus::NodeId getShortClassId() {return SHORT_CLASS_ID;}
        inline static columbus::NodeId getIntegerClassId() {return INTEGER_CLASS_ID;}
        inline static columbus::NodeId getLongClassId() {return LONG_CLASS_ID;}
        inline static columbus::NodeId getObjectClassId() {return OBJECT_CLASS_ID;}
        inline static columbus::NodeId getStringClassId() {return STRING_CLASS_ID;}
        inline static columbus::NodeId getStringTypeId() {return STRING_TYPE_ID;}

        inline static columbus::NodeId getFloatClassId() {return FLOAT_CLASS_ID;}
        inline static columbus::NodeId getDoubleClassId() {return DOUBLE_CLASS_ID;}
        inline static columbus::NodeId getFloatNaNId() {return FLOAT_NAN;}
        inline static columbus::NodeId getFloatNegativeInfinityId() {return FLOAT_NEGATIVE_INFINITY;}
        inline static columbus::NodeId getFloatPositiveInfinityId() {return FLOAT_POSITIVE_INFINITY;}
        inline static columbus::NodeId getDoubleNaNId() {return DOUBLE_NAN;}
        inline static columbus::NodeId getDoubleNegativeInfinityId() {return DOUBLE_NEGATIVE_INFINITY;}
        inline static columbus::NodeId getDoublePositiveInfinityId() {return DOUBLE_POSITIVE_INFINITY;}


        static columbus::NodeId getResultType(NodeId type1, NodeId type2);
    };

}}

#endif
