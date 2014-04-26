#include "RecoVertex/ConfigurableVertexReco/interface/VertexFitterManager.h"
#include "RecoVertex/ConfigurableVertexReco/interface/VertexRecoManager.h"
#include "RecoVertex/ConfigurableVertexReco/interface/ReconstructorFromFitter.h"

using namespace std;

void VertexFitterManager::registerFitter (
      const string & name, std::function<AbstractConfFitter*()> o, const string & d )
{
  theAbstractConfFitters[name]=o;
  theDescription[name]=d;

  // every fitter registers as a reconstructor, also
  VertexRecoManager::Instance().registerReconstructor ( name, [o]()->AbstractConfReconstructor* { return new ReconstructorFromFitter ( *(o()) );}, d);
}

VertexFitterManager::~VertexFitterManager()
{
}

std::string VertexFitterManager::describe ( const std::string & d ) const
{
  auto found = theDescription.find(d);
  if(found == theDescription.end()) {
    return std::string{};
  }
  return found->first;
}

VertexFitterManager * VertexFitterManager::clone() const
{
  return new VertexFitterManager ( * this );
}

VertexFitterManager::VertexFitterManager ( const VertexFitterManager & o ) 
{
  std::cout << "[VertexFitterManager] copy constructor! Error!" << std::endl;
  exit(0);
  /*
  for ( map < string, AbstractConfFitter * >::const_iterator i=o.theAbstractConfFitters.begin(); 
        i!=o.theAbstractConfFitters.end() ; ++i )
  {
    theAbstractConfFitters[ i->first ] = i->second->clone();
  }
  
  theIsEnabled=o.theIsEnabled;
  */
}

VertexFitterManager & VertexFitterManager::Instance()
{
  static VertexFitterManager singleton;
  return singleton;
}

std::unique_ptr<AbstractConfFitter> VertexFitterManager::get ( const string & s ) const
{
  auto found = theAbstractConfFitters.find(s);
  if(found == theAbstractConfFitters.end()) {
    return std::unique_ptr<AbstractConfFitter>{};
  }
  return std::unique_ptr<AbstractConfFitter>{found->second()};
}

std::vector<std::string> VertexFitterManager::getNames() const 
{
  std::vector<std::string> ret;
  ret.reserve(theAbstractConfFitters.size());

  for(const auto& i : theAbstractConfFitters) {
    ret.push_back(i.first);
  }
  return ret;
}

VertexFitterManager::VertexFitterManager()
{}
