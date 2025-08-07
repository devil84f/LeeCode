 import { Routes, Route } from "react-router-dom";
 import { useState } from "react";
 import { AuthContext } from '@/contexts/authContext';
import { ResourceProvider } from '@/contexts/resourceContext.tsx';
 
 // 页面导入
 import Home from "@/pages/Home";
 import ResourceList from "@/pages/ResourceList";
 import ResourceDetail from "@/pages/ResourceDetail";
 import ResourceForm from "@/pages/ResourceForm";
 import TypeManagement from "@/pages/TypeManagement";
 
 export default function App() {
   const [isAuthenticated, setIsAuthenticated] = useState(true); // 默认已登录状态，实际项目中应实现登录功能
 
   const logout = () => {
     setIsAuthenticated(false);
   };
 
   return (
     <AuthContext.Provider
       value={{ isAuthenticated, setIsAuthenticated, logout }}
     >
       <ResourceProvider>
         <Routes>
           <Route path="/" element={<Home />} />
           <Route path="/resources/:typeId" element={<ResourceList />} />
           <Route path="/resource/:id" element={<ResourceDetail />} />
           <Route path="/resource/upload" element={<ResourceForm />} />
           <Route path="/resource/edit/:id" element={<ResourceForm />} />
           <Route path="/types/manage" element={<TypeManagement />} />
           <Route path="*" element={<div className="text-center text-xl py-10">页面未找到</div>} />
         </Routes>
       </ResourceProvider>
     </AuthContext.Provider>
   );
 }
