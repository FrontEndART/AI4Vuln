#ifndef CG2GRAPHML_H
#define	CG2GRAPHML_H

#include "cfg/inc/cfg.h"
#include <io/inc/GraphmlIO.h>

namespace columbus {
    namespace cfg {

        class CG2Graphml {
        private:

            /** \brief The GraphmlIO pointer that will point to a GraphmlIO, that can write elements into the graphml. */
            io::GraphmlIO *graphmlIO;

        public:
            /**
             * \brief Constructor.
             */
            CG2Graphml();

            /**
             * \brief Copy constructor.
             */
            CG2Graphml(const CG2Graphml& orig);

            /**
             * \brief operator "=" overloading.
             */
            CG2Graphml& operator=(const CG2Graphml& node);

            /**
             * \brief Destructor.
             */
            virtual ~CG2Graphml();

            /**
             * \brief Converts the given CG to a given named constraint graph .graphml.
             * \param cgFactory            [in] The CGFactory which needs to be convert to .grpahml.
             * \param cgGraphOutputName    [in] The graphml file output name.
             * \param print                [in] Optional printer that can convert node to something else.
             */
            void convertCG2Graphml(CGFactory& cgFactory, const std::string &cgGraphOutputName, ASGNodePrinter* print = NULL);
        private:

        };
    }
}
#endif
