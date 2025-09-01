#ifndef _CFGGRAPHML2CFG_H
#define _CFGGRAPHML2CFG_H

#include "cfg/inc/cfg.h"
#include <io/inc/SimpleXmlIO.h>

namespace columbus {  namespace cfg {

    
class CFGGraphml2CFG{
private:
    /**
     * \brief Inner CFGGraphmlHandler class, that is responsible for travel the xml tags and contents and for build the CFG in CFGFactory. 
     */
    class CFGGraphmlHandler : public io::SimpleXmlIO::XmlHandler{
    private:
        /**
         * \brief Pointer of the CFGFactory, within we want to build the CFG. 
         */
        CFGFactory* cfgFactory;

        /**
         * \brief Bool logical value to know, if we are after a group node tag in the graphml. 
         */
        bool wasGroup;

        /**
         * \brief Bool logical value to know, if we are after an y:NodeLabel tag in the graphml, that is within a group node. 
         */
        bool wasGroupNodeLabel;

        /**
         * \brief Bool logical value to know, if we are after a node tag, that has only the id attribute in the graphml. 
         */
        bool wasSimpleNode;

        /**
         * \brief Bool logical value to know, if we are after an y:NodeLabel tag in the graphml, that is within a simple node. 
         */
        bool wasSimpleNodeLabel;

        /**
         * \brief Storage for graphml group node id and ICFG method id pairs. 
         */
        std::map<std::string, unsigned int> groupWithMethodContainer;

        /**
         * \brief Storage for graphml simple node id and BasicBlock block id pairs. 
         */
        std::map<std::string, unsigned int> nodeWithBlockContainer;

        /**
         * \brief The actual graphml group or simple node id. 
         */
        std::string actualId;

        /**
         * \brief Reads group and simple node tag, sets actualId and node logical values.
         * \param list [in] The tag attributes.
         */
        void readNodes(const AttributeList& list);

        /**
         * \brief Reads an edge and connect the source and target BasicBlocks with the correct type of the read edge.
         * \param list [in] The tag attributes.
         */
        void readEdges(const AttributeList& list);
    public:
        CFGGraphmlHandler(CFGFactory* cfgFactory);
        CFGGraphmlHandler(const CFGGraphmlHandler& cfgGraphmlHandler);
        CFGGraphmlHandler& operator=(const CFGGraphmlHandler& cfgGraphmlHandler);

        /**
          * \brief Overloaded beginTag, it recognizes the .graphml tags, which are needed fog CFG.
          * \param name [in] The tag name.
          * \param list [in] The tag attruibutes.
          */
        void beginTag(const std::string& name, const AttributeList& list);

        /**
         * \brief Overloaded content, reads the group Node or dimple Node labels.
         * \param content [in] The content text.
         */
        void content(const std::string& content);
    };
public:
    CFGGraphml2CFG();

    /**
     * \brief Reads a .graphml file, that contains a control flow graph.
     * \param inFilename    [in] The .graphml file name, that should be read.
     * \param cfgFactory    [out] The CFGFactory, that will be contain the readed CFG.
     */
    void readGraphml(const std::string& inFilename, CFGFactory& cfgFactory);

};

}}

#endif
