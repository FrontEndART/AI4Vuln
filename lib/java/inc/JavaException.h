#ifndef _JAVA_EXCEPTION_H_
#define _JAVA_EXCEPTION_H_

#include "java/inc/java.h"

/**
* \file JavaException.h
* \brief Contains declaration for the common (base) class of all java Exceptions.
*/

namespace columbus { namespace java { namespace asg {
  /**
  * \brief General (base) class for all java::Exception.
  */
  class JavaException : public columbus::Exception {
    public:
      /**
      * \brief Constructor.
      * \param location [in] The location of the exception (the "place" where the exception was thrown).
      * \param message  [in] The cause of the exception.
      */
      JavaException(const std::string &location, const std::string &message);

      /**
      * \brief Destructor.
      */
      virtual ~JavaException();

      /**
      * \brief Gives back the name of the java::JavaException class.
      * \return Returns the name of the java::JavaException class.
      */
      virtual const std::string getClassName() const;

  }; // JavaException


  /**
  * \brief Thrown by ListIterator if the iterator is invalid.
  */
  class JavaInvalidIteratorException : public JavaException {
    public:
      /**
      * \brief Constructor.
      * \param location [in] The location of the exception (the "place" where the exception was thrown).
      * \param message  [in] The cause of the exception.
      */
      JavaInvalidIteratorException(const std::string &location, const std::string &message);

      /**
      * \brief Destructor.
      */
      virtual ~JavaInvalidIteratorException();

      /**
      * \brief Gives back the name of the Java::JavaInvalidIteratorException class.
      * \return Returns the name of the Java::JavaInvalidIteratorException class.
      */
      virtual const std::string getClassName() const;

  }; // JavaInvalidIteratorException


  /**
  * \brief Thrown by ListIterator if illegal operation is executed on an iterator.
  */
  class JavaIllegalStateException : public JavaException {
    public:
      /**
      * \brief Constructor.
      * \param location [in] The location of the exception (the "place" where the exception was thrown).
      * \param message  [in] The cause of the exception.
      */
      JavaIllegalStateException(const std::string &location, const std::string &message);

      /**
      * \brief Destructor.
      */
      virtual ~JavaIllegalStateException();

      /**
      * \brief Gives back the name of the Java::IllegalStateException class.
      * \return Returns the name of the Java::IllegalStateException class.
      */
      virtual const std::string getClassName() const;

  }; // JavaIllegalStateException


  /**
  * \brief Thrown by ListIterator if next()(or pervious() ) is called and there is no next (previous) element.
  */
  class JavaNoSuchElementException : public JavaException {
    public:
      /**
      * \brief Constructor.
      * \param location [in] The location of the exception (the "place" where the exception was thrown).
      * \param message  [in] The cause of the exception.
      */
      JavaNoSuchElementException(const std::string &location, const std::string &message);

      /**
      * \brief Destructor.
      */
      virtual ~JavaNoSuchElementException();

      /**
      * \brief Gives back the name of the java::JavaNoSuchElementException class.
      * \return Returns the name of the java::JavaNoSuchElementException class.
      */
      virtual const std::string getClassName() const;

  }; // JavaNoSuchElementException



}}}
#endif

